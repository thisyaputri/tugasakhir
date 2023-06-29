#include <iostream>
#include <string>

using namespace std;

class Ruko {
private:
    string fasilitas;
    float luas;
    int harga;

public:
    Ruko() {
        fasilitas = "";
        luas = 0.0;
        harga = 0;
    }

    void setInfo(string fasilitas, float luas, int harga) {
        this->fasilitas = fasilitas;
        this->luas = luas;
        this->harga = harga;
    }

    void tampilkanInfo() {
        cout << "Fasilitas: " << fasilitas << endl;
        cout << "Luas: " << luas << " meter persegi" << endl;
        cout << "Harga Sewa: Rp" << harga << endl;
    }

    int getHarga() const {
        return harga;
    }
};

void selectionSort(Ruko arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j].getHarga() < arr[minIndex].getHarga()) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    Ruko persewaanRuko[5]; // Array objek persewaan ruko

    for (int i = 0; i < 5; i++) {
        cout << "Persewaan Ruko #" << (i + 1) << endl;

        string fasilitas;
        float luas;
        int harga;

        cout << "Masukkan fasilitas: ";
        getline(cin, fasilitas);

        cout << "Masukkan luas (meter persegi): ";
        cin >> luas;

        cout << "Masukkan harga sewa: Rp";
        cin >> harga;

        cin.ignore(); // Membersihkan karakter newline di input

        persewaanRuko[i].setInfo(fasilitas, luas, harga);

        cout << endl;
    }

    cout << "Informasi Persewaan Ruko sebelum diurutkan" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Persewaan Ruko #" << (i + 1) << endl;
        persewaanRuko[i].tampilkanInfo();
        cout << endl;
    }

    selectionSort(persewaanRuko, 5);

    cout << "Informasi Persewaan Ruko setelah diurutkan berdasarkan harga sewa" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Persewaan Ruko #" << (i + 1) << endl;
        persewaanRuko[i].tampilkanInfo();
        cout << endl;
    }

    return 0;
}
