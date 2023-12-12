#include "protagonistviewtext.h"
#include <iostream>
#include <QTextBlock>

ProtagonistViewText::ProtagonistViewText()
{

}

void ProtagonistViewText::update()
{
    auto xPos = protModel->getPositionX();
    auto yPos = protModel->getPositionY();


    update(xPos,yPos);
    updateHealth();

}

void ProtagonistViewText::update(int row, int col)
{

    erasePreviousPosition();

    int newMoveDown = row > 0 ? 1 + 2 * row : row + 1;
    int newMoveRight = 2 + 4 * col;

    auto cursor = textEdit->textCursor();
    auto newBlock = textEdit->document()->findBlockByLineNumber(newMoveDown);


    // Update the new position
    QTextCursor newCursor(newBlock);
    newCursor.movePosition(QTextCursor::StartOfBlock);
    newCursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, newMoveRight);
    newCursor.deleteChar();
    newCursor.insertText("P");

}

void ProtagonistViewText::erasePreviousPosition() {


    int oldMoveDown = protModel->getPositionX() > 0 ? 1 + 2 * protModel->getPositionX() : protModel->getPositionX() + 1;
    int oldMoveRight = 2 + 4 * protModel->getPositionY();

    QTextBlock oldBlock = textEdit->document()->findBlockByLineNumber(oldMoveDown);
    QTextCursor oldCursor(oldBlock);

    oldCursor.movePosition(QTextCursor::StartOfBlock);
    oldCursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, oldMoveRight);
    oldCursor.deleteChar();
    oldCursor.insertText(" ");
}


void ProtagonistViewText::updateHealth()
{
    int health = protModel->getCurrentHealth();
    int maxHealth = protModel->getMaxhealth();
    healthValueLabel->setText(QString::number(health) + " / " + QString::number(maxHealth));
}



void ProtagonistViewText::clearView()
{
    textEdit.reset();
    //healthLabel.reset();
    healthValueLabel.reset();
}

void ProtagonistViewText::setProtModel(const std::shared_ptr<ProtagonistModel> &newProtModel)
{
    protModel = newProtModel;
}

void ProtagonistViewText::setTextEdit(const std::shared_ptr<QPlainTextEdit> &newTextEdit)
{
    textEdit = newTextEdit;
}

void ProtagonistViewText::setHealthLabels(std::shared_ptr<QLabel> healthValue) {
    healthValueLabel = healthValue;
}
