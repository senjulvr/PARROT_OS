#include <stdio.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;

    if (sysinfo(&info) == 0) {
        printf("System Uptime: %ld seconds\n", info.uptime);
        printf("Total RAM: %lu MB\n", info.totalram / (1024 * 1024));
        printf("Free RAM: %lu MB\n", info.freeram / (1024 * 1024));
        printf("Load Averages (1, 5, 15 min): %lu, %lu, %lu\n",
               info.loads[0], info.loads[1], info.loads[2]);
    } else {
        perror("sysinfo");
    }

    return 0;
}
