#include "MessageBox.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

MessageBox::MessageBox(const QString &title, const QString &text, QWidget *parent) : QDialog(parent)
{
    QDialog::setWindowTitle(title);

    QLabel* label = new QLabel(this);
    label->setText(text);

    QPushButton *ok = new QPushButton("确定");
    QPushButton *cancel = new QPushButton("取消");

    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->addWidget(ok,3);
    btnLayout->addStretch(2);
    btnLayout->addWidget(cancel,3);
    btnLayout->setMargin(0);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addStretch();
    layout->addLayout(btnLayout);
    layout->setMargin(10);

    connect(ok, &QPushButton::clicked, [this]{setResult(QDialog::Accepted);this->hide();});
    connect(cancel, &QPushButton::clicked, [this]{setResult(QDialog::Rejected);this->hide();});
}

