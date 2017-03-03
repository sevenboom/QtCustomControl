#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QWidget>

class QPushButton;
class QLabel;
class PopupListView;

class ComboBox : public QWidget
{
    Q_OBJECT
public:
    explicit ComboBox(QWidget *parent = 0);

signals:

public slots:

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QLabel *m_line;
    QPushButton *m_drop;
    PopupListView *m_popup;
};

#endif // COMBOBOX_H
