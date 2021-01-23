
class CNode
{
private:
	char data;
	CNode* next;
	CNode* back;
public:
	CNode(char data) : data{ data }, next{ nullptr }, back{ nullptr } {}
	CNode* getNext();
	CNode* getBack();
	char getData();
	void setData(char);
	void setNext(CNode*);
	void setBack(CNode*);
};
