#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-auto"
#include <iostream>
#include "Experiments.h"


int main() {
    experiments::FindExperimentsWorker *find = new experiments::FindExperimentsWorker;
    experiments::SortExperimentsWorker *sort = new experiments::SortExperimentsWorker();
    experiments::PopFExperimentsWorker *popf = new experiments::PopFExperimentsWorker();
    experiments::PopBExperimentsWorker *popb = new experiments::PopBExperimentsWorker();
    experiments::PushFExperimentsWorker *pushf = new experiments::PushFExperimentsWorker();
    experiments::PushBExperimentsWorker *pushb = new experiments::PushBExperimentsWorker();
    find->run();
    sort->run();
    popf->run();
    popb->run();
    pushf->run();
    pushb->run();
    return 0;
}

#pragma clang diagnostic pop