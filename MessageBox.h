#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QDialog>

class MessageBox : public QDialog
{
    Q_OBJECT
public:
//    explicit MessageBox(QWidget *parent = 0);
    explicit MessageBox(const QString &title, const QString &text, QWidget *parent = 0);

};

#endif // MESSAGEBOX_H
