#include "combobox.h"
#include "popuplistview.h"

#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

ComboBox::ComboBox(QWidget *parent) : QWidget(parent)
{
    m_line = new QLabel("combo box line");
    m_drop = new QPushButton();
    m_drop->setStyleSheet("QPushButton{border-image:url(:/ComboBox/controlsource/dropArrow.png);}"
                          "QPushButton::pressed{border-image:url(:/ComboBox/controlsource/dropArrow1.png)}"
                          );

    m_popup = new PopupListView(this);
    m_popup->hide();

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(m_line,5);
    layout->addWidget(m_drop,1);
    layout->setMargin(0);
    layout->setSpacing(2);

    connect(m_drop, &QPushButton::clicked, [this]{
        const QPoint &pos =mapToGlobal(QPoint(0,0));
        m_popup->popup(pos.x(), pos.y()+this->height());
    });
}

void ComboBox::resizeEvent(QResizeEvent *event)
{
    qDebug() << "resize popup";
    m_popup->resize(this->width(), 5*this->height());
}
