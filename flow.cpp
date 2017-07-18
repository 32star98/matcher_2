#include "stdafx.h"
#include "flow.h"


void flow::endbranch(flow * newer)
{
}

void flow::add(flow * newer)
{
	ph_nex = newer;
	ext = newer;
}

flow::flow()
{
}


flow::~flow()
{
}
