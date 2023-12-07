#include <stdio.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_TITLE_LENGTH 50
#define MAX_DESC_LENGTH 100
#define MAX_DEADLINE_LENGTH 20

//Struktur untuk menyimpan informasi tugas 
struct Task {
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESC_LENGTH];
    char deadline[MAX_DEADLINE_LENGTH];
    int isCompleted;
    int progress; 
};

//fungsi untuk menampilkan menu 
void displayMenu (){
    printf("\n\t\t================================\n");
    printf("\n\t\t==== Sistem Manajemen Tugas ====\n");
    printf("\n\t\t================================\n");
    printf("\n\t\tHalo, selamat datang disini :D. \n\t\tKan kubuat harimu indah dan santuy\n\n");
    printf("1. Tambah Tugas \n");
    printf("2. Hapus Tugas\n");
    printf("3. Tampilkan Daftar Tugas\n");
    printf("4. Perbarui Progress Tugas\n"); 
    printf("5. Keluar\n");
    printf("Pilih aksi(1-4):");
}

//fungsi untuk menambahkan tugas
void addTask (struct Task tasks[], int *taskCount){
    if (*taskCount < MAX_TASKS) {
        printf("Masukkan judul tugas:");
        scanf(" %[^\n]s", tasks[*taskCount].title); //membaca judul dengan spasi 
        printf("Masukkan deskripsi tugas:");  
        scanf(" %[^\n]s", tasks[*taskCount].description); //membaca deskripsi dengan spasi
        
        printf("Masukkan deadline tugas:");
        scanf(" %[^\n]s", tasks[*taskCount].deadline);

        printf("Masukkan persentase progress tugas:");
        scanf(" %d", &tasks[*taskCount].progress);
        
        tasks[*taskCount].isCompleted = (tasks[*taskCount].progress == 100);
        (*taskCount)++;
        
        printf("Tugas berhasil ditambahkan!\n");
    } else {
        printf("Daftar tugas penuh. hapus beberapa tugas terlebih dahulu.\n");
    }
}

//fungsi untuk menghapus tugas dari daftar 
void removeTask(struct Task tasks[], int *taskCount) {
    if (*taskCount > 0 ){
        int taskIndex;
        printf("Masukkan nomor tugas yang akan dihapus(1-%d):",*taskCount);
        scanf("%d", &taskIndex);
        
        if (taskIndex >= 1 && taskIndex <= *taskCount){
            //menggeser tugas yang tersisa setelah tugas dihapus
         for (int i= taskIndex-1; i<*taskCount-1;i++){
             tasks[i]= tasks[i+1];
         }
         
         (*taskCount)--;
         printf("Tugas berhasil dihapus!\n");
        } else {
            printf("Nomor tugas tidak valid.\n");
        } 
        } else {
            printf("Daftar tugas kosong.\n");
      }
}

//fungsi untuk menampilkan daftar tugas 
void displayTask(struct Task tasks[], int taskCount){
    if (taskCount > 0) {
        printf("\n==== Daftar Tugas ====\n");
        for (int i=0; i < taskCount;i++){
            printf("Nomor Tugas: %d\n", i+1);
            printf("Judul:%s\n",tasks[i].title);
            printf("Deksripsi: %s\n",tasks[i].description);
            printf("Deadline: %s\n", tasks[i].deadline);
            printf("Persentase Progress: %d%%\n", tasks[i].progress);
            printf("Status: %s\n", tasks[i].isCompleted ? "Selesai" : "Belum Selesai");
            printf("\n");
        }
    } else {
        printf("Daftar tugas kosong.\n");
    }
}

//fungsi untuk update progress
void updateProgress(struct Task tasks[], int taskCount) {
    if (taskCount > 0) {
        int taskIndex;
        printf("Masukkan nomor tugas untuk diperbarui progressnya(1-%d):", taskCount);
        scanf("%d", &taskIndex);

        if (taskIndex >= 1 && taskIndex <= taskCount) {
            printf("Masukkan persentase progress baru untuk tugas '%s': ", tasks[taskIndex - 1].title);
            scanf("%d", &tasks[taskIndex - 1].progress);

            tasks[taskIndex - 1].isCompleted = (tasks[taskIndex - 1].progress == 100);
            printf("Progress tugas berhasil diperbarui!\n");
        } else {
            printf("Nomor tugas tidak valid.\n");
        }
    } else {
        printf("Daftar tugas kosong.\n");
    }
}

//fungsi utama sistem
int main (){
    struct Task tasks[MAX_TASKS];
    int taskCount = 0; 
    int choice;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
            addTask(tasks, &taskCount);
            break;
            case 2: 
            removeTask(tasks, &taskCount);
            break;
            case 3: 
            displayTask(tasks,taskCount);
            break;
            case 4:
            updateProgress(tasks, taskCount);
            break;
            case 5: 
            printf("keluar dari program. Sampai jumpa!\n");
            break;
            default:
            printf("Pilihan tidak valid. Silakan masukkan pilihan yang benar.\n");
        }
    } while (choice != 5);
    
    return 0;
}