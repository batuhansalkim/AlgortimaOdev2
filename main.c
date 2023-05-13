#include <stdio.h>

// Binary Search algoritmasi
int binary_search(int dizi[], int solTaraf, int sagTaraf, int arananEleman) {
    if (solTaraf > sagTaraf) {
        return -1;
    }

    int orta = (solTaraf + sagTaraf) / 2;

    if (dizi[orta] == arananEleman) {
        return orta;
    } else if (dizi[orta] > arananEleman) {
        return binary_search(dizi, solTaraf, orta-1, arananEleman);
    } else {
        return binary_search(dizi, orta+1, sagTaraf, arananEleman);
    }
}

int main() {
    int dizi[] = {4, 8, 3, 84, 47, 76, 9, 24, 68};
    int n = sizeof(dizi) / sizeof(dizi[0]);

    // Diziyi küçükten büyüge sirala
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (dizi[j] > dizi[j+1]) {
                int temp = dizi[j];
                dizi[j] = dizi[j+1];
                dizi[j+1] = temp;
            }
        }
    }

    // Diziyi ekrana yazdir
    printf("Dizi: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");

    // Aranacak elemani kullanicidan iste
    int aranan;
    printf("Aranacak elemani girin: ");
    scanf("%d", &aranan);

    // Binary Search ile arama yap
    int sonuc = binary_search(dizi, 0, n-1, aranan);
    if (sonuc != -1) {
        printf("Aranan eleman dizide %d. sirada bulundu.\n", sonuc+1);
    } else {
        printf("Aranan eleman dizide bulunamadi.\n");
    }

    return 0;
}
