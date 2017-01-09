#ifndef __ASSEMBLER_H__
#define __ASSEMBLER_H__

#include <fstream>
#include <string>
#include "bundle_base.h"
#include "bundle.h"
#include "genome.h"

using namespace std;

class assembler
{
public:
	assembler();
	~assembler();

private:
	samFile *sfn;
	bam_hdr_t *hdr;
	bam1_t *b1t;
	vector<bundle_base> vbb;
	vector<bundle_base> pool;

	int index;
	bool terminate;

	genome gm;
	int qcnt;
	double qlen;

public:
	int assemble();

private:
	int process(int n);
	int add_hit(const hit &ht);
	int truncate(const hit &ht);
	int assemble(const bundle_base &bb);
	int filter_transcripts(gene &gn);
	int compare(splice_graph &gr, const string &ref, const string &tex = "");
};

#endif
