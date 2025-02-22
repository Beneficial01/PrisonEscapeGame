/**
 * @file tileview.h
 * @brief Defines the abstract TileView class for managing tile views in a game environment.
 *
 * This file contains the TileView class, an abstract class responsible for defining the structure
 * and interface for managing and updating tile views in a game environment. It includes methods for
 * updating the view, clearing the display, and setting the associated TileModel.
 */

#ifndef TILEVIEW_H
#define TILEVIEW_H

#include "tilemodel.h"
class TileView
{
public:

    /**
     * @brief Updates the view at the specified row and column.
     * @param row Row index to update (default: 0).
     * @param col Column index to update (default: 0).
     */
    virtual void update(int row = 0, int col = 0) = 0;

    /**
     * @brief Clears the entire view.
     * Clears the display of all tiles. Used before switching to a new view
     */
    virtual void clearView() = 0;

    /**
     * @brief Sets the TileModel for the TileView.
     * @param newTileModel Shared pointer to the TileModel instance to be set.
     */
    virtual void setTileModel(const std::shared_ptr<TileModel> &newTileModel) = 0;

protected:
    std::shared_ptr<TileModel> tileModel; /**< Shared pointer to the associated TileModel.*/
};


#endif // TILEVIEW_H
