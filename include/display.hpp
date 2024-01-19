#pragma once

#include "tasklist.hpp"

namespace Display {
   void help();
   void tasks(TaskList *taskList);
   void taskAddedSuccessfully();
   void taskNotAdded();
   void taskCheckedOut();
   void taskNotFound();
   void fileNotFound();
}
