#include "graph.cpp" 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2){
        std::cout << "Arquivo de entrada não especificado. Uso: " << argv[0] << " <arquivo>" << std::endl;
        return 1;
    }

    std::ifstream arq(argv[1]);

    if (!arq.is_open()) {
        std::cout << "Erro ao abrir o arquivo: " << argv[1] << std::endl;
        return 1;
    }

    graph::digraph g;

    std::string leitura;

    getline(arq, leitura);

    int arestas_inseridas = 0;

    while (getline(arq, leitura)) {
        if (leitura.empty())
            continue;

        std::stringstream ss(leitura);

        std::string prb_id;
        std::string probe_src;
        std::string dst_addr;
        std::string hop;
        std::string hop_from;
        std::string hop_to;
        std::string rtt;

        getline(ss, prb_id, ',');
        getline(ss, probe_src, ',');
        getline(ss, dst_addr, ',');
        getline(ss, hop, ',');
        getline(ss, hop_from, ',');
        getline(ss, hop_to, ',');
        getline(ss, rtt, ',');

        if (hop_from.empty() || hop_to.empty() || hop_to == "*") {
            continue;
        }

        if (!g.find(hop_from))
            g.insert_nodo(hop_from);

        if (!g.find(hop_to))
            g.insert_nodo(hop_to);

        if (g.insert_link(hop_from, hop_to))
            arestas_inseridas++;
    }

    std::cout << "\nTudo Ok!\n";

    std::cout << "Vertices unicos:" << g.size() << "\n";

    std::cout << "Arestas: " << arestas_inseridas << "\n";

    return 0;
}