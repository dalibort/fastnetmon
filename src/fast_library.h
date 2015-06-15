#ifndef FAST_LIBRARY_H
#define FAST_LIBRARY_H

#include "fastnetmon_types.h"

#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <sstream>

#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/regex.hpp>

// Boost libs
#include <boost/algorithm/string.hpp>

#include "libpatricia/patricia.h"

#define TCP_FIN_FLAG_SHIFT 1
#define TCP_SYN_FLAG_SHIFT 2
#define TCP_RST_FLAG_SHIFT 3
#define TCP_PSH_FLAG_SHIFT 4
#define TCP_ACK_FLAG_SHIFT 5
#define TCP_URG_FLAG_SHIFT 6

typedef std::map<std::string, uint64_t> graphite_data_t;
typedef std::vector<std::string> interfaces_list_t;
typedef std::vector<std::string> ip_addresses_list_t;

ip_addresses_list_t get_local_ip_addresses_list();
ip_addresses_list_t get_ip_list_for_interface(std::string interface);
interfaces_list_t get_interfaces_list();

bool store_data_to_graphite(unsigned short int graphite_port, std::string graphite_host, graphite_data_t graphite_data);
std::string get_protocol_name_by_number(unsigned int proto_number);
uint64_t convert_speed_to_mbps(uint64_t speed_in_bps);
std::vector<std::string> exec(std::string cmd);
uint32_t convert_ip_as_string_to_uint(std::string ip);
std::string convert_ip_as_uint_to_string(uint32_t ip_as_integer);
std::string convert_int_to_string(int value);
std::string print_simple_packet(simple_packet packet);
std::string convert_timeval_to_date(struct timeval tv);

int extract_bit_value(uint8_t num, int bit);
int extract_bit_value(uint16_t num, int bit);

int clear_bit_value(uint8_t& num, int bit);
int clear_bit_value(uint16_t& num, int bit);

int set_bit_value(uint8_t& num, int bit);
int set_bit_value(uint16_t& num, int bit);

std::string print_tcp_flags(uint8_t flag_value);
uint64_t MurmurHash64A(const void* key, int len, uint64_t seed);
std::string print_tcp_flags(uint8_t flag_value);
int timeval_subtract(struct timeval* result, struct timeval* x, struct timeval* y);
bool folder_exists(std::string path);
bool is_cidr_subnet(const char* subnet);
bool file_exists(std::string path);
uint32_t convert_cidr_to_binary_netmask(unsigned int cidr);
std::string get_printable_protocol_name(unsigned int protocol);
std::string get_net_address_from_network_as_string(std::string network_cidr_format);
std::string print_time_t_in_fastnetmon_format(time_t current_time);
unsigned int get_cidr_mask_from_network_as_string(std::string network_cidr_format);
void copy_networks_from_string_form_to_binary(std::vector<std::string> networks_list_as_string,
                                              std::vector<subnet_t>& our_networks);
int convert_string_to_integer(std::string line);

// Byte order type safe converters
uint16_t fast_ntoh(uint16_t value);
uint32_t fast_ntoh(uint32_t value);
uint64_t fast_ntoh(uint64_t value);

uint16_t fast_hton(uint16_t value);
uint32_t fast_hton(uint32_t value);
uint64_t fast_hton(uint64_t value);

void print_pid_to_file(pid_t pid, std::string pid_path);
bool read_pid_from_file(pid_t& pid, std::string pid_path);

std::string convert_prefix_to_string_representation(prefix_t* prefix);
std::string find_subnet_by_ip_in_string_format(patricia_tree_t* patricia_tree, std::string ip);
std::string convert_subnet_to_string(subnet_t my_subnet);

#endif
