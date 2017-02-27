#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QLabel;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

    void showMsgBox();

private:
    QLabel *m_statusBar; // ×´Ì¬À¸
};

#endif // MAINWINDOW_H
