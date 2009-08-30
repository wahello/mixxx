// sidebarmodel.h 
// Created 8/21/09 by RJ Ryan (rryan@mit.edu)

#ifndef SIDEBARMODEL_H
#define SIDEBARMODEL_H

#include <QAbstractItemModel>
#include <QList>
#include <QModelIndex>
#include <QVariant>

class LibraryFeature;

class SidebarModel : public QAbstractItemModel {
    Q_OBJECT
public:
    explicit SidebarModel(QObject* parent = 0);
    virtual ~SidebarModel();
    
    void addLibraryFeature(LibraryFeature* feature);
    QModelIndex getDefaultSelection();
    void activateDefaultSelection();
    
    // Required for QAbstractItemModel
    QModelIndex index(int row, int column,
                      const QModelIndex& parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex& index) const;
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index,
                  int role = Qt::DisplayRole ) const;
    bool dropAccept(const QModelIndex& index, QUrl url);
    bool dragMoveAccept(const QModelIndex& index, QUrl url);
public slots:
    void clicked(const QModelIndex& index);
    void rightClicked(const QPoint& globalPos, const QModelIndex& index);     
    void refreshData();   
private:
    QList<LibraryFeature*> m_sFeatures;
};

#endif /* SIDEBARMODEL_H */
