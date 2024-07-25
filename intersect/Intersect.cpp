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

intersect::Object intersect::IntersectArea(Object& first, Object& second)
{
	Object ret = { -1, -1, -1, -1 };

	if (!(first.left >= second.right || first.right <= second.left || first.down <= second.up || first.up >= second.down))
	{
		if (first.left < second.left && first.right > second.right)
		{
			ret.left = second.left;
			ret.right = second.right;
		}
		else if (first.left < second.left && first.right >= second.left && first.right <= second.right)
		{
			ret.left = second.left;
			ret.right = first.right;
		}
		else if (first.right > second.right && first.left >= second.left && first.left <= second.right)
		{
			ret.left = first.left;
			ret.right = second.right;
		}
		else
		{
			if (first.left >= second.left && first.left <= second.right)ret.left = first.left;
			if (first.right >= second.left && first.right <= second.right)ret.right = first.right;
		}

		if (first.up < second.up && first.down > second.down)
		{
			ret.up = second.up;
			ret.down = second.down;
		}
		else if (first.up < second.up && first.down >= second.up && first.down <= second.down)
		{
			ret.up = second.up;
			ret.down = first.down;
		}
		else if (first.down > second.down && first.up >= second.up && first.up <= second.up)
		{
			ret.up = first.up;
			ret.down = second.down;
		}
		else
		{
			ret.up = first.up;
			ret.down = first.down;
		}
	}
	return ret;
}
