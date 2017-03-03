#include "popuplistview.h"

#include <QFocusEvent>
#include <QLabel>
#include <QPainter>
#include <QStringListModel>
#include <QTextOption>
#include <QDebug>

PopupListView::PopupListView(QWidget *parent) : QWidget(parent)
{
    this->setFocusPolicy(Qt::ClickFocus);
    this->setWindowFlags(Qt::Popup|Qt::FramelessWindowHint);
//    this->setAutoFillBackground(true);
//    QPalette pal = this->palette();
//    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/LoginSettings/Resources/LoginSettings/clssdropdown.png").scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
//    this->setPalette(pal);
    this->setStyleSheet("#PopupListView{border-image:url(:/ComboBox/controlsource/clssdropdown.png)}");
    this->hide();

    m_view = new QListView(this);
    m_view->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    m_view->setFrameShape(QFrame::NoFrame);
    m_view->setItemDelegate(new ItemDelegate(this));
    m_view->setFocusProxy(this);
    m_view->setStyleSheet("QScrollBar:vertical\
    {\
        width:15px;\
        background:rgba(0,0,0,0);\
        padding-bottom:9px;                        \
        background-position: right;\
    }                                              \
    QScrollBar::handle:vertical                    \
    {                                              \
        width:15px;\
        background:rgb(197,234,255); \
        border-radius:7px;                      \
        min-height:30px;                      \
    }                                              \
    QScrollBar::add-line:vertical\
    {\
        height:0px;width:0px;\
        subcontrol-position:bottom;\
    }\
    QScrollBar::sub-line:vertical\
    {\
        height:0px;width:0px;\
        subcontrol-position:top;\
    }");

    connect(m_view, &QListView::clicked,this,&PopupListView::selectResult);
}

void PopupListView::popup(int x, int y)
{
    qDebug() << "popup x"<< x <<", y" << y;
    if(x==0&&y==0){
        m_is_popuped = false;

    }else{
        m_is_popuped = !m_is_popuped;
    }
    setVisible(m_is_popuped);
    if(m_is_popuped){
        this->move(x,y);
        this->raise();
        this->setFocus();
    }
}

int PopupListView::getSchoolId() const
{
    return m_school_id;
}

void PopupListView::focusOutEvent(QFocusEvent *event)
{
    this->setVisible(false);
    m_is_popuped =false;
}

void PopupListView::resizeEvent(QResizeEvent *event)
{
    m_view->setGeometry(20,25,this->width()-40,this->height()-50);
}

void PopupListView::getListModel(const QMap<QString, QVariant> &school_list)
{
//    QStringList school_name_list;
//    for(QVariant school: school_list){
////        qDebug() << school;
//        school_name_list.append(school.toMap().first().toMap()["name"].toString());
//        m_school_list.append(school.toMap().first());
//    }
//    qDebug() <<"get school list" << school_name_list;
//    QStringListModel *model = new QStringListModel(school_name_list,this);
//    QItemSelectionModel *m = m_view->selectionModel();
//    m_view->setModel(model);
//    delete m;
//    m_view->update();
}

void PopupListView::getSchoolInfo(bool is_success, QMap<QString, QVariant> data)
{
//    if(!is_success){
//        qDebug() << data["error"].toString();
//        return;
//    }
//    if(data.isEmpty()){
//        qDebug() << QString::fromLocal8Bit("获取学校列表为空");
//    }

//    qDebug() << "get school data" << data;

//    QMap<QString, QVariant> var_map = data["objMap"].toMap()["200"].toMap();
//    getListModel(var_map);
}

void PopupListView::selectResult(const QModelIndex &index)
{
    if(index.isValid()){
        if(index.data().isValid()){
            emit currentData(index.data().toString());
            m_school_id = m_school_list.at(index.row()).toMap()["id"].toInt();
            this->hide();
            m_is_popuped = false;
        }
    }
}

void PopupListView::setUserId(int user_id)
{
    m_user_id = user_id;
}

void PopupListView::setCountyCode(int code)
{

}

/*!*************************************************************************************
 * view中item的委托类
 **********************************************************************************************/

ItemDelegate::ItemDelegate(QObject *parent)
{

}

void ItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QString text = index.model()->data(index, Qt::DisplayRole).toString();
//    qDebug() << option.checkState << option.state;
    if(option.state&(QStyle::State_MouseOver)){
        painter->fillRect(option.rect, QColor("#f5f8fa"));
    }
    QTextOption o(Qt::AlignLeft | Qt::AlignVCenter);
    o.setWrapMode(QTextOption::NoWrap);
    painter->setPen(QColor("#a3a5a6"));
    painter->setFont(QFont("Microsoft YaHei", 15));
    painter->drawText(option.rect, text, o);
}

QSize ItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSize size = option.rect.size();
    return QSize(size.width(),50);
}

QWidget *ItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLabel * label = new QLabel(parent);
    label->setGeometry(option.rect);
    return label;
}

void ItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString str = index.model()->data(index, Qt::DisplayRole).toString();
    QLabel *label = qobject_cast<QLabel *>(editor);
    label->setText(str);
}

void ItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLabel *label = qobject_cast<QLabel *>(editor);
    QString text = label->text();
    model->setData(index, text);
}
