#include <iostream>
#include "Experiments.h"

int main() {
    experiments::FindExperimentsWorker find = experiments::FindExperimentsWorker();
    experiments::SortExperimentsWorker sort = experiments::SortExperimentsWorker();
    experiments::PopFExperimentsWorker popf = experiments::PopFExperimentsWorker();
    experiments::PopBExperimentsWorker popb = experiments::PopBExperimentsWorker();
    experiments::PushFExperimentsWorker pushf = experiments::PushFExperimentsWorker();
    experiments::PushBExperimentsWorker pushb = experiments::PushBExperimentsWorker();
    find.run();
    sort.run();
    popf.run();
    popb.run();
    pushf.run();
    pushb.run();
    return 0;
}
