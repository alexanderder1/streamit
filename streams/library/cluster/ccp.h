#ifndef __CCP_H
#define __CCP_H

#include <netsocket.h>
#include <ccp_session.h>

#include <vector>
#include <map>

using namespace std;

class ccp {

  int number_of_threads;
  int machines_in_partition;
  map<int, int> partition;         // from thread to machine id

  map<int, unsigned> machines;     // from machine id to ip address

  bool waiting_to_start_execution;
  int initial_iteration;

  vector <ccp_session*> sessions;
  
  void read_config_file();
  void assign_nodes_to_partition();

  void send_cluster_config(int iter = 0);

  void handle_change_in_number_of_nodes();
  void execute_partitioner(int number_of_nodes);

 public:

  ccp();

  void set_init_iter(int iter);

  int run_ccp();

};


#endif