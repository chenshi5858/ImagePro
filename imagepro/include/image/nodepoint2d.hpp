/*
 Class NodePoint2D
*/

namespace image {
	class NodePoint2D{
	private:
	int row;
	int col;
	NodePoint2D* ptr_next;		
	public:
	NodePoint2D();
	NodePoint2D(int fila, int columna, NodePoint2D* siguiente=nullptr);
	int getRow();
	int getCol();
	NodePoint2D* getNext();
	void setRow(int fila);
	void setCol(int columna);
	void setNext(NodePoint2D *nuevo);
	};
}
