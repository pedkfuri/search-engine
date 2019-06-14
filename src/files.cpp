#include "../include/files.h"

using namespace std;

vector<Doc> Files::readFiles() {
	DIR *dir = NULL;
    dirent *file = NULL;
    dir = opendir("docs/"); //diretório de todos os documentos
    vector<Doc> docs;

    if(dir == NULL) {
    	cout << "Não foi possível acessar o diretório de documentos. Experimente trocar o nome da pasta com dataset para \"docs\"." << endl;
    }

    while((file = readdir(dir)) != NULL) {
    	if (file == NULL) {
    		cout << "Erro no processamento do arquivo da base dados. Experimente deixar apenas arquivos com a extensão .txt no diretório." << endl;
    	}

    	if (strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0) { //utiliza a biblioteca cstring
    		docs.push_back(Doc(file->d_name));
    	}
    }
    closedir(dir);
    return docs;
}

void Files::getTerms(vector<Doc>& docs, Index& index) {
	for (Doc& doc : docs) {
		ifstream file;
		file.open("docs/" + doc.getDocName());
		string word;

		while (file >> word) {
			normalizeTerm(word);
			Term wordAdd(word);
			addToDoc(doc, Term(wordAdd));
			addToII(doc, index, Term(wordAdd));
		}
	}

}

void Files::addToII(Doc& doc, Index& Index, Term term) {
	set<Doc>& assocDocs = Index.getRegs()[term];

	if (assocDocs.find(doc) == assocDocs.end()) {
		assocDocs.insert(doc);
	}
}

void Files::addToDoc(Doc& doc, Term term) {
	map<Term, int>& terms = doc.getTerms();
	terms[term]++;
}

void Files::normalizeTerm(string& word) {
	string norm;
	for (auto& ch : word) {
		if (!ispunct((unsigned char)ch)) {
			norm += tolower((unsigned char)ch);
		}
	}
	word = norm;
}