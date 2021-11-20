
#include <bits/stdc++.h>

using namespace std;

int n;
double res = 0.0;
bool res_i = false;

int data_n[10000] = {0};
bool mod_n[10000] = {0};

//void op()
//{
//	for (int i = 1; i < n - 1; i++)
//		a[i] = a[i - 1] + a[i + 1] - a[i];
//}


void dyn_op(int data[], int layer, bool mod[], int tari)
{
	int data_c[10000];
	bool mod_c[10000];
	memcpy(data_c, data, 10000 * sizeof(int));
	memcpy(mod_c, mod, 10000 * sizeof(bool));
	data_c[tari] = data_c[tari - 1] + data_c[tari + 1] - data_c[tari];
	for (int i = 1; i < n - 1; i++) {
		if (!mod_c[i]) {
			mod_c[i] = true;
			dyn_op(data_c, layer + 1, mod_c, i);
			mod_c[i] = false;
		}
	}
	
	double av = 0;
	for (int i = 0; i < n; i++)
		av += data_c[i];
	av /= (double) n;
	double curres = 0.0;
	for (int i = 0; i < n; i++)
		curres += pow(abs(data_c[i] - av), 2);
	if (res_i) {
		if (curres < res) {
//			cout << "new min res: " << curres << endl;
//			cout << "data: ";
//			for (int i = 0; i < n; i++)
//				cout << data_c[i] << " ";
//			cout << endl;
			res = curres;
		}
	} else {
		res = curres;
		res_i = true;
	}
}

int main()
{
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", data_n + i);
	}
//	for (int i = 1; i < n - 1; i++) {
//		arr[i] = arr[i - 1] + arr[i + 1] - arr[i];
//		cout << "a: " << arr[i] << endl;
//		double av = 0;
//		for (int i = 0; i < n; i++)
//			av += arr[i];
//		av /= (double) n;
//		double curres = 0.0;
//		for (int i = 0; i < n; i++)
//			curres += pow(abs(arr[i] - av), 2);
//		cout << "curres: " << curres << endl;
//		if (res_i) {
//			if (curres < res)
//				res = curres;
//		} else {
//			res = curres;
//			res_i = true;
//		}
//	}
	for (int i = 1; i < n - 1; i++) {
		dyn_op(data_n, 0, mod_n, i);
	}
	printf("%d\n", (int) (res * n));
	return 0;
}


