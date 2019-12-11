#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/shm.h>

#define TEST_SHM_SIZE (65536)
#define FLAGS         (IPC_CREAT | IPC_EXCL | 0600)

int main()
{
    int shmid;
    key_t shmkey;
   
    shmkey = getpid();
    while ((shmid = shmget(shmkey, TEST_SHM_SIZE, FLAGS)) == EEXIST) ++shmkey;

    printf("shmid: %d\nerrno: %d\n", shmid, errno);

    if (shmid == -1) return errno;

    if (shmctl(shmid, IPC_RMID, NULL) == -1) printf("Could not IPC_RMID!\n");

    return 0;
}
