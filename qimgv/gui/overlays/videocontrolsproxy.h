#pragma once

#include "gui/overlays/videocontrols.h"

struct VideoControlsStateBuffer {
    int duration = 0;
    int position = 0;
    bool paused = true;
    bool videoMuted = true;
    PlaybackMode mode;
};

class VideoControlsProxyWrapper : public QObject {
    Q_OBJECT
public:
    explicit VideoControlsProxyWrapper(FloatingWidgetContainer *parent = nullptr);
    ~VideoControlsProxyWrapper();
    void init();

    void show();
    void hide();
    bool underMouse();
    bool isVisible();
    // Get the actual geometry of the video controls in the parent widget's coordinate system
    QRect geometry() const;

signals:
    void seek(int pos);
    void seekForward();
    void seekBackward();
    void setVolume(int pos);

public slots:
    void setPlaybackDuration(int);
    void setPlaybackPosition(int);
    void setMode(PlaybackMode);
    void onPlaybackPaused(bool);
    void onVideoMuted(bool);

private:
    FloatingWidgetContainer *container;
    VideoControls *videoControls;
    VideoControlsStateBuffer stateBuf;
};
