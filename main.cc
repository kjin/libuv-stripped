#include "uv.h"
#include <fstream>

#define GET_CGROUPS(TYPE, CONTROLLER, FIELD) \
  TYPE FIELD; \
  { \
    std::ifstream cgroup_file; \
    cgroup_file.open("/sys/fs/cgroup/" #CONTROLLER "/" #CONTROLLER "." #FIELD); \
    cgroup_file >> FIELD; \
    cgroup_file.close(); \
  }

int main(int argc, char **argv) {
  // Memory comparison
  {
    // libuv
    printf("uv_get_total_memory: %llu\n", uv_get_total_memory());
  }
  {
    // libuv
    printf("uv_get_constrained_memory: %llu\n", uv_get_constrained_memory());
  }
  {
    // cgroups
    GET_CGROUPS(int64_t, memory, limit_in_bytes);
    printf("memory.limit_in_bytes: %lld\n", limit_in_bytes);
  }
  {
    // libuv
    printf("uv_get_free_memory: %llu\n", uv_get_free_memory());
  }
  {
    // cgroups
    GET_CGROUPS(int64_t, memory, usage_in_bytes);
    printf("memory.usage_in_bytes: %lld\n", usage_in_bytes);
  }
  // CPU comparison
  {
    // libuv
    int cpu_count;
    uv_cpu_info_t* cpu_infos;
    uv_cpu_info(&cpu_infos, &cpu_count);
    printf("uv_cpu_info count: %d\n", cpu_count);
    uv_free_cpu_info(cpu_infos, cpu_count);
  }
  {
    GET_CGROUPS(int64_t, cpu, cfs_period_us);
    printf("cpu.cfs_period_us: %lld\n", cfs_period_us);
    GET_CGROUPS(int64_t, cpu, cfs_quota_us);
    printf("cpu.cfs_quota_us: %lld\n", cfs_quota_us);
  }
}
