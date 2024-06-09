#include "customsortfilterproxymodel.h"

CustomSortFilterProxyModel::CustomSortFilterProxyModel(QObject* parent)
    : QSortFilterProxyModel(parent) {}

bool CustomSortFilterProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const {
    if (left.column() == 4 && right.column() == 4) {
        int leftData = sourceModel()->data(left, Qt::UserRole).toInt();
        int rightData = sourceModel()->data(right, Qt::UserRole).toInt();
        return leftData < rightData;
    }
    return QSortFilterProxyModel::lessThan(left, right);
}
