#ifndef POPUPLISTVIEW_H
#define POPUPLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QWidget>

class PopupListView : public QWidget
{
    Q_OBJECT
public:
    explicit PopupListView(QWidget *parent = 0);
    void setUserId(int id);

signals:
    void currentData(QString school_name);

public slots:
    void setCountyCode(int  code );
    void popup(int x, int y);
    int getSchoolId()const;

protected:
    void focusOutEvent(QFocusEvent *event);
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void getListModel(const QMap<QString, QVariant> &schools);
    void getSchoolInfo(bool is_success, QMap<QString, QVariant> data);
    void selectResult(const QModelIndex &index);

private:
    QListView *m_view;
    int m_user_id = -1;// 管理员id
    bool m_is_popuped = false;
    QVariantList m_school_list;
    int m_school_id = -1;
};

//
class  ItemDelegate: public  QStyledItemDelegate
{
    Q_OBJECT
public:
    ItemDelegate(QObject *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

private:
};

#endif // POPUPLISTVIEW_H
