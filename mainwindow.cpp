#include "mainwindow.h"
#include "MessageBox.h"
#include "ComboBox/combobox.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *msgDialog = new QPushButton("MessageBox");

    m_statusBar = new QLabel;

    ComboBox *comboBox = new ComboBox();
    comboBox->setMaximumSize(100,40);

    QHBoxLayout *dailogLayout = new QHBoxLayout();
    dailogLayout->addWidget(msgDialog,0,Qt::AlignLeft);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addLayout(dailogLayout);
    layout->addWidget(comboBox, 0, Qt::AlignLeft);
    layout->addWidget(m_statusBar, 0, Qt::AlignBottom);

    connect(msgDialog, &QPushButton::clicked, this, &MainWidget::showMsgBox);
}

MainWidget::~MainWidget()
{

}

void MainWidget::showMsgBox()
{
    MessageBox msgBox("信息","这是一个简单的自定义message box",this);
    msgBox.exec();
    qDebug() << msgBox.result();
    QString &&res = QString("已选择:");
    m_statusBar->setText(res+(msgBox.result()==1?"确定":"取消"));
}
