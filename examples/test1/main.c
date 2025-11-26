#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#include <rte_eal.h>
#include <rte_ethdev.h>

int main(int argc, char **argv) {
    int ret = rte_eal_init(argc, argv);
    if (ret < 0) {
        rte_exit(EXIT_FAILURE, "Error with EAL initialization\n");
    }

    uint16_t nb_ports = rte_eth_dev_count_avail();
    printf("Available ports: %" PRIu16 "\n", nb_ports);

    for (uint16_t port_id = 0; port_id < nb_ports; port_id++) {
        struct rte_eth_dev_info dev_info;
        rte_eth_dev_info_get(port_id, &dev_info);
        printf("Port %u: driver=%s\n", port_id, dev_info.driver_name);
    }

    return 0;
}