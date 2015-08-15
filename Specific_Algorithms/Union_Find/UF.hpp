#ifndef UF_H
#define UF_H

class UF
{

	public:
	UF(int N);
	void union (int p, int q);
	boolean connected (int p, int q);
	int find (int p);
	int count();

};


#endif
