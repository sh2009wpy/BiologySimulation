#ifndef MITOCHONDRION_H
#define MITOCHONDRION_H

class Mitochondrion {
public:
    Mitochondrion();

    // 丙酮酸氧化: pyruvate -> Acetyl-CoA + NADH
    void pyruvateOxidation(double &pyruvate, double &nadh, double &acetylCoA);

    // 三羧酸循环: Acetyl-CoA -> NADH + FADH2 + ATP
    double citricAcidCycle(double &acetylCoA, double &nadh, double &fadh2);

    // 电子传递链: NADH/FADH2 + O2 -> ATP
    double electronTransportChain(double &nadh, double &fadh2, double &oxygen);
};

#endif
