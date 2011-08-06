/* -*- c++ -*- */
/*
 * Copyright 2011 Alexandru Csete OZ9AEC.
 *
 * Gqrx is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * Gqrx is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Gqrx; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */
#ifndef DOCKIQPLAYER_H
#define DOCKIQPLAYER_H

#include <QDockWidget>
#include <QTimer>
#include <QTime>


namespace Ui {
    class DockIqPlayer;
}


/*! \brief I/Q playback widget.
 *
 * This dock widget is used to replay previously recorded I/Q data files.
 * The widget contains and button to load a file, a play button, a seek
 * slider and two labels showing the current posision and the duration of
 * the recording.
 *
 * The play button is only active if a file has been loaded.
 * The seek slider is only active while playing.
 */
class DockIqPlayer : public QDockWidget
{
    Q_OBJECT

public:
    explicit DockIqPlayer(QWidget *parent = 0);
    ~DockIqPlayer();

    void setPos(int pos);

signals:
    void fileOpened(const QString filename);
    void playbackToggled(bool play, const QString filename);
    void posChanged(int new_pos);

private slots:
    void on_openButton_clicked();
    void on_playButton_clicked(bool checked);
    void on_seekSlider_valueChanged(int pos);

private:  
    Ui::DockIqPlayer *ui;  /*! UI generated by Qt Designer. */
    QString  d_fileName;    /*! Currently loaded file name. */
    int      d_pos;         /*! Last set play position. */
    int      d_samprate;    /*! Current sample rate of input file. */
    int      d_bps;         /*! Byter / sample. */
    qint64   d_duration;    /*! Duration of current recording (sec). */

    /** FIXME: use state? **/

};

#endif // DOCKIQPLAYER_H
