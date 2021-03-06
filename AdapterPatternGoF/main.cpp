#include<iostream>
#include "TextView(Target).h"
#include "Shape(Adaptee).h"

#include "ShapeToText(Adapter).h"

#include "ShapeToText(ObjectAdapter).h"
using namespace std;

int main()
{
	cout << "Main Start\n";

	//We will now work on Shape object, which will enternally communate with TextObject to get its work done.
	//it can do seperate work also(like Manipulation) which TextView does not support

	ShapeToTextClassAdapter *shapeAdapter = new ShapeToTextClassAdapter();

	Point bottomLeft, bottomRight;
	shapeAdapter->BoundingBox(bottomLeft, bottomRight); //get Drawing reason

	void* manipulatorObject = shapeAdapter->CreateManipulator(); //using this we can perfrom some operation on set of Shape objects.
	//doMove(manipulatorObject)

	//Operation on shape without Help of TextView
	Shape s;
	s.BoundingBox(bottomLeft,bottomRight);

	//Object Adapter
	ShapeToTextObjectAdapter *shapeAdapter2 = new ShapeToTextObjectAdapter(new TextView());
	shapeAdapter2->BoundingBox(bottomLeft, bottomRight); //get Drawing reason	

	return 0;
}