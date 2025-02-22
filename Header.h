#pragma once
#include "Reservoir.h"
#include "delete_error.h"
#include "error_with_file.h"

reservoir* adding(reservoir* reserviors, int& size);

reservoir* deleting(reservoir* reserviors, int& size);

reservoir* add_copy(reservoir* reserviors, int& size);

int add_file(reservoir* reserviors, int size);