#include "include.h"
#include "NeuralNetwork.h"
#include "CLA.h"

int main(int argc, char** argv) {
    CLA::parse(argc, argv);

    vector<int> layerCount;

    // Check for command line arguments
    if (CLA::layers.size() >= 3) {
        for (int layer : CLA::layers) {
            layerCount.push_back(layer);
        }
    }

    const auto start_begin = chrono::high_resolution_clock::now();

    NeuralNetwork nn;

    // If valid arguments are given
    if (layerCount.size() > 0)
        nn = NeuralNetwork(layerCount, 0.9, CLA::verbose);

    const auto start_end = chrono::high_resolution_clock::now();

    // Training
    const auto train_begin = chrono::high_resolution_clock::now();

    nn.train(1000);

    for (Node &node : (nn.layers.end() - 1)->nodes) {
        cout << "Result: " << node.normalized << endl;
    }

    const auto train_end = chrono::high_resolution_clock::now();

    const auto start_time = chrono::duration_cast<chrono::milliseconds>(start_end - start_begin).count();
    const auto train_time = chrono::duration_cast<chrono::milliseconds>(train_end - train_begin).count();

    cout << "Start time elapsed: " << start_time << "ms" << endl
         << "Train time elapsed: " << train_time << "ms" << endl;

    // if (CLA::wait) {
        cout << "Press any key to exit the process...";
        getchar();
    // }

    return 0;
}
