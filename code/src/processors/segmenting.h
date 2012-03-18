#ifndef SEGMENTING_H
#define SEGMENTING_H

#include "processor.h"

using namespace cv;

class Segmenting : public Processor
{
  Q_OBJECT

  Q_PROPERTY(Mode SegmentingMode READ mode WRITE setMode DESIGNABLE true USER true)
  Q_PROPERTY(bool DarkBackground READ darkBG WRITE setDarkBG DESIGNABLE true USER true)
  Q_PROPERTY(int Threshold READ threshold USER true)
  Q_ENUMS(Mode)

public:
  enum Mode { GLOBAL_THRESHOLD, ADAPTIVE_THRESHOLD, SPLIT_MERGE };
  Segmenting(QObject *parent = 0);
  ~Segmenting();

  QString name() {return "Segmenting";}

  bool darkBG() const {return m_dark_bg;}
  void setDarkBG(const bool bg);

  Mode mode() const {return m_mode;}
  void setMode(const Mode mode);

  int threshold() const {return m_threshold;}

public slots:
  void process();

private:
  void thresholdSegment(bool adapt);
  void adaptThreshold();
  void splitMerge();
  int m_threshold;
  bool m_dark_bg;
  Mode m_mode;
};

#endif
