1:singlenode:: NODE* singlenode:: delete_node()
NODE是singlenode的其中一個成員，宣告NODE的函式時必須說明NODE屬於誰的成員

2:將唯一的頭節點當成物件的其中一個成員，使其他函式可以直接用this呼叫他(this->head)

3:加入建構子與解構子，建構子自動產生頭節點，結構子自動歸還所有節點記憶體