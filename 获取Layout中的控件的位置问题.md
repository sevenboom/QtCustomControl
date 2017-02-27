#在布局定义时获取布局中的控件中的位置都是0，
``` c++
QWidget *control1 = new QWidget;
QWidget *control2 = new Qwidget;
QVBoxLayout *Right_Layout = new QVBoxLayout();
Right_Layout->addStretch();
Right_Layout->addWidget(control1,0,Qt::AlignHCenter);
Right_Layout->addWidget(control2,0,Qt::AlignHCenter);
Right_Layout->addStretch();
Right_Layout->setContentsMargins(0, 0, 0, 0);

// 输出x, y都为0
qDebug() << "get control's pos " << m_ClassTextDisplay->x() << "  " << m_ClassTextDisplay->y;
···