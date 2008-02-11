// .NAME vtkSlicerGradientEditorWidget 
// .SECTION Description
// This class implements Slicer's main GradientsEditor GUI.
// Inherits most behavior from vtkSlicerWidget.
#ifndef __vtkSlicerGradientEditorWidget_h
#define __vtkSlicerGradientEditorWidget_h

#include "vtkSlicerWidget.h"
#include "vtkSlicerMeasurementFrameWidget.h"
#include "vtkSlicerGradientsWidget.h"

class vtkSlicerNodeSelectorWidget;
class vtkMRMLDiffusionWeightedVolumeNode;
//widgets
class vtkKWFrameWithLabel;
class vtkKWPushButton;

class VTK_SLICER_BASE_GUI_EXPORT vtkSlicerGradientEditorWidget : public vtkSlicerWidget
  {
  public:

    // Description:
    // Usual vtk class functions.
    static vtkSlicerGradientEditorWidget* New();
    vtkTypeRevisionMacro(vtkSlicerGradientEditorWidget,vtkSlicerWidget);
    void PrintSelf(ostream& os, vtkIndent indent);

    // Description:
    // Add/Remove observers on widgets in the GUI.
    virtual void AddWidgetObservers();
    virtual void RemoveWidgetObservers();

    // Description:
    // Method to propagate events generated in GUI to logic / mrml.
    void ProcessWidgetEvents(vtkObject *caller, unsigned long event, void *callData );

    // Description:
    // Method to update the widget when a new node is loaded.
    void UpdateWidget(vtkMRMLDiffusionWeightedVolumeNode *node);

  protected:
    vtkSlicerGradientEditorWidget(void);
    virtual ~vtkSlicerGradientEditorWidget(void);

    // Description:
    // Method to create the widget.
    virtual void CreateWidget();

    vtkMRMLDiffusionWeightedVolumeNode *ActiveVolumeNode;
    vtkMRMLDiffusionWeightedVolumeNode *OriginalNode;
    int NumberUndosAfterLoading;    
    //widgets (GUI)
    vtkSlicerMeasurementFrameWidget *MeasurementFrameWidget;
    vtkSlicerGradientsWidget *GradientsWidget;
    vtkKWFrameWithLabel *TestFrame;
    vtkSlicerNodeSelectorWidget *FiducialSelector;
    vtkKWPushButton *RunButton;    
    vtkKWPushButton *RestoreButton;
    vtkKWPushButton *UndoButton;    

  private:
    vtkSlicerGradientEditorWidget (const vtkSlicerGradientEditorWidget&); // Not implemented.
    void operator = (const vtkSlicerGradientEditorWidget&); //Not implemented.
  };

#endif 
