#ifndef CELL_H
#define CELL_H

#include "Mitochondrion.h"

class Cell {
public:
    double sugar;    // 细胞质糖
    double atp;      // 细胞总ATP
    double oxygen;   // 线粒体氧
    double pyruvate; // 糖酵解产物
    double acetylCoA;
    double nadh;
    double fadh2;

    Mitochondrion mito;

    Cell(double init_sugar=1.0, double init_oxygen=6.0, double init_atp=0.0);

    void glycolysis();            // 在细胞质中进行
    void mitochondrialRespiration(); // 线粒体代谢
    void metabolize();            // 完整代谢流程
};

#endif
