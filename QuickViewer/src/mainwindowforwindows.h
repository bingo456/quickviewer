#ifndef MAINWINDOWFORWINDOWS_H
#define MAINWINDOWFORWINDOWS_H

#include "mainwindow.h"
#include <Windows.h>

class MainWindowForWindows : public MainWindow
{
    Q_OBJECT
public:
    MainWindowForWindows(QWidget *parent = 0);
    virtual bool moveToTrush(QString path) override;
    virtual bool setStayOnTop(bool top) override;
    virtual void setWindowTop() override;
    virtual void setMailAttachment(QString path) override;
    virtual bool eventFilter(QObject *obj, QEvent *event) override;
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);

public slots:
    virtual void on_hover_anchor(Qt::AnchorPoint anchor) override;
    virtual void on_fullscreen_triggered() override;

private:
    bool bFirstView;
    HMENU m_showMainMenu; // HMENU

    static MainWindowForWindows* MainWindowForWindows_self;
    static WNDPROC DefStaticProc;
    static LRESULT CALLBACK StaticProc(HWND hwnd , UINT msg , WPARAM wp , LPARAM lp);
};

#endif // MAINWINDOWFORWINDOWS_H
