#include <stdio.h>

// Binary Search algoritmasý
int binary_search(int dizi[], int sol, int sag, int aranan) {
    if (sol > sag) {
        return -1;
    }

    int orta = (sol + sag) / 2;

    if (dizi[orta] == aranan) {
        return orta;
    } else if (dizi[orta] > aranan) {
        return binary_search(dizi, sol, orta-1, aranan);
    } else {
        return binary_search(dizi, orta+1, sag, aranan);
    }
}

int main() {
    int dizi[] = {4, 8, 3, 84, 47, 76, 9, 24, 68};
    int n = sizeof(dizi) / sizeof(dizi[0]);

    // Diziyi küçükten büyüðe sýrala
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (dizi[j] > dizi[j+1]) {
                int temp = dizi[j];
                dizi[j] = dizi[j+1];
                dizi[j+1] = temp;
            }
        }
    }

    // Diziyi ekrana yazdýr
    printf("Dizi: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");

    // Aranacak elemaný kullanýcýdan iste
    int aranan;
    printf("Aranacak elemani girin: ");
    scanf("%d", &aranan);

    // Binary Search ile arama yap
    int sonuc = binary_search(dizi, 0, n-1, aranan);
    if (sonuc != -1) {
        printf("Aranan eleman dizide %d. sýrada bulundu.\n", sonuc+1);
    } else {
        printf("Aranan eleman dizide bulunamadi.\n");
    }

    return 0;
}
