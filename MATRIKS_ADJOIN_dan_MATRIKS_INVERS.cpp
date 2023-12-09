#include<iostream>
using namespace std;

// Fungsi untuk mendapatkan kofaktor dari matriks
void getCofactor(int mat[3][3], int temp[3][3], int p, int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

// Fungsi untuk menghitung determinan matriks
int determinant(int mat[3][3], int n)
{
    int D = 0;
    if (n == 1)
        return mat[0][0];

    int temp[3][3];
    int sign = 1;
    for (int f = 0; f < n; f++)
    {
        getCofactor(mat, temp, 0, f, n);
        D += sign * mat[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }
    return D;
}

// Fungsi untuk menghitung adjoint dari matriks
void adjoint(int mat[3][3], int adj[3][3])
{
    if (3 == 1)
    {
        adj[0][0] = 1;
        return;
    }
    int sign = 1, temp[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            getCofactor(mat, temp, i, j, 3);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = (sign) * (determinant(temp, 3 - 1));
        }
    }
}

// Fungsi untuk menghitung invers dari matriks
void inverse(int mat[3][3], float inv[3][3])
{
    int det = determinant(mat, 3);
    int adj[3][3];
    adjoint(mat, adj);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            inv[i][j] = adj[i][j] / float(det);
}

int main()
{
    int choice;

    cout << "======== Program Untuk Mengerjakan MATRIKS ADJOIN dan MATRIKS INVERS =========\n";

    do
    {
        cout << "\nPilihan Menu:\n";
        cout << "1. Kerjakan soal no 1\n";
        cout << "2. Kerjakan soal no 2\n";
        cout << "3. Kerjakan soal no 3\n";
        cout << "4. Kerjakan soal no 4\n";
        cout << "5. Kerjakan soal no 5\n";
        cout << "6. Kembali ke menu awal\n";
        cout << "7. Keluar\n";
        cout << "Pilih soal (1-7): ";
        cin >> choice;
        cout << "\n";

        switch (choice)
        {
        case 1:
        {
            int a[2][2] = {{2, -2}, {-2, 3}};
            int adj[2][2];

            // hitung adjoint
            adj[0][0] = a[1][1];
            adj[0][1] = -a[0][1];
            adj[1][0] = -a[1][0];
            adj[1][1] = a[0][0];

            cout << "Adjoint dari matriks A adalah: \n";
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    cout << adj[i][j] << " ";
                }
                cout << "\n";
            }
            break;
        }
        case 2:
        {
            int a[2][2] = {{5, -1}, {-4, 6}};
            int adj[2][2];

            // hitung adjoint
            adj[0][0] = a[1][1];
            adj[0][1] = -a[0][1];
            adj[1][0] = -a[1][0];
            adj[1][1] = a[0][0];

            cout << "Adjoint dari matriks A adalah: \n";
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    cout << adj[i][j] << " ";
                }
                cout << "\n";
            }
            break;
        }
        case 3:
        {
            int mat[3][3] = {{3, 1, 0}, {2, 1, 1}, {6, 2, 2}};
            int adj[3][3];
            adjoint(mat, adj);

            cout << "Adjoint dari matriks A adalah: \n";
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << adj[i][j] << " ";
                }
                cout << "\n";
            }
            break;
        }
        case 4:
        {
            int a[2][2] = {{2, -2}, {-2, 3}};
            int adj[2][2];
            float inv[2][2];

            // hitung adjoint
            adj[0][0] = a[1][1];
            adj[0][1] = -a[0][1];
            adj[1][0] = -a[1][0];
            adj[1][1] = a[0][0];

            // hitung determinan
            int det = a[0][0] * a[1][1] - a[0][1] * a[1][0];

            // hitung invers
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    inv[i][j] = adj[i][j] / float(det);
                }
            }

            cout << "Invers dari matriks A adalah: \n";
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    cout << inv[i][j] << " ";
                }
                cout << "\n";
            }
            break;
        }
        case 5:
        {
            int mat[3][3] = {{2, -3, 1}, {0, 2, 1}, {-2, 1, 3}};
            float inv[3][3];
            inverse(mat, inv);

            cout << "Invers dari matriks A adalah: \n";
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << inv[i][j] << " ";
                }
                cout << "\n";
            }
            break;
        }
        case 6:
            // Do nothing, will go back to the menu
            break;
        case 7:
            cout << "Terima kasih telah menggunakan program ini. Sampai jumpa!";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
        }

    } while (choice != 7);

    return 0;
}
