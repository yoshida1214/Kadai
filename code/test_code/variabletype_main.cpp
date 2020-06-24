#include "..\header\VariableType.h"
#include "..\header\Stack.h"
#include <iostream>
#include <string>
using namespace std;

typedef struct _lakeData {
	int start_X;
	int AreaValue;
}LakeData;

int main() {

	Stack<LakeData> L_st;
	Stack<int> D_st;
	string str;
	getline(cin, str);
	int *area;
	int cnt,all;

	for (int i = 0;i < str.size();i++) {
		if (str[i] == '\\') {
			D_st.Push(i);
		}
		else if (str[i] == '/') {
			if (D_st.GetSize() != 0) {
				int start = D_st.Pop();
				int all_area = 0;
				LakeData l_data;
				if (L_st.GetSize() != 0) {
					l_data = L_st.Pop();
					if (l_data.start_X > start) {
						//while (l_data.start_X > start) {
						//	all_area += l_data.AreaValue;
						//	if (L_st.GetSize() != 0)
						//		l_data = L_st.Pop();
						//	else
						//		break;
						//}
						//L_st.Push(l_data);
						//all_area += (i - start);
						//l_data.start_X = start;
						//l_data.AreaValue = all_area;
						//L_st.Push(l_data);
						do {
							all_area += l_data.AreaValue;
							if (L_st.GetSize() != 0)
								l_data = L_st.Pop();
							else
								break;
							if (l_data.start_X < start)
								L_st.Push(l_data);

						} while (l_data.start_X > start);
						all_area += (i - start);
						l_data.start_X = start;
						l_data.AreaValue = all_area;
						L_st.Push(l_data);
					}
					else {
						L_st.Push(l_data);
						l_data.start_X = start;
						l_data.AreaValue = (i - start);
						L_st.Push(l_data);
					}
				}
				else {
					l_data.start_X = start;
					l_data.AreaValue = (i - start);
					L_st.Push(l_data);
				}
			}
		}
	}

	all = 0;
	cnt = L_st.GetSize();
	area = new int[cnt];

	for (int i = cnt-1;i >= 0;i--) {
		area[i] = L_st.Pop().AreaValue;
		all += area[i];
	}
	cout << all << " " << endl;
	cout << cnt;
	for (int i = 0;i < cnt;i++) {
		cout << " " << area[i];
	}
	cout << endl;

	delete[] area;
	return 0;

}