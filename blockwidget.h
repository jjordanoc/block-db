#ifndef BLOCKWIDGET_H
#define BLOCKWIDGET_H

#include "blockidinputbox.h"
#include <QTextEdit>
#include <QVBoxLayout>
#include<QWidget>
#include "block.h"
#include "globals.h"

class BlockWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BlockWidget(const size_t &id, const size_t &nonce, const std::string &hashCode, QWidget *parent);
    explicit BlockWidget(Block<BLOCK_SIZE> *_block, QWidget *parent);
    void updateBlockData();
signals:
private:
    BlockInputBox *id{};
    BlockInputBox *nonce{};
    BlockInputBox *hashCode{};
    BlockInputBox *prev{};
    BlockInputBox *blockData{};
    Block <BLOCK_SIZE> *block{};
    QVBoxLayout *layout{};
};

#endif // BLOCKWIDGET_H
