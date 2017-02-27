#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QLabel>
#include <QWidget>

class ComboBox : public QWidget
{
    Q_OBJECT
public:
    explicit ComboBox(QWidget *parent = 0);

signals:

public slots:

private:
    QLabel *m_line;
    QLabel *
};

#endif // COMBOBOX_H
