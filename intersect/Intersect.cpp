#include "pch.h"
#include "intersect.h"

collision intersect::IsThereCollision(Object& first, Object& second)
{
	collision to_where = collision::no;

	if (!(first.left >= second.right || first.right <= second.left || first.down <= second.up || first.up >= second.down))
	{
		if (first.down <= second.up)
		{
			if (first.right <= second.left)to_where = collision::down_left;
			else if (first.left >= second.right)to_where = collision::down_right;
			else to_where = collision::down;
		}
		else if (first.up >= second.down)
		{
			if (first.right <= second.left)to_where = collision::up_left;
			else if (first.left >= second.right)to_where = collision::up_right;
			else to_where = collision::up;
		}
		else if (first.right <= second.left)to_where = collision::left;
		else if (first.left >= second.right)to_where = collision::right;

	}

	return to_where;
}
