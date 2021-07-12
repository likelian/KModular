/*
  ==============================================================================

    KM_PresentManager.cpp
    Created: 10 Jul 2021 4:29:34pm
    Author:  李克镰

  ==============================================================================
*/

#include "KM_PresentManager.h"
//#include "KM_PanelBase.h"

#if JUCE_WINDOWS
static const juce::String DirectorySeperator = "\\";
#elif JUCE_MAC
static const juce::String DirectorySeperator = "/";
#endif


KM_PresentManager::KM_PresentManager(juce::AudioProcessor* inProcessor)

:
    mCurrentPresetSaved(false),
    mCurrentPresetName("Untitled"),
    mProcessor(inProcessor)
{
    
    const juce::String PluginName = (juce::String)mProcessor->getName();
    
    mPresetDirectory = juce::File::getSpecialLocation(juce::File::userDesktopDirectory).getFullPathName()
        +DirectorySeperator
        +PluginName;
    
    if(!juce::File(mPresetDirectory).exists()){ //if mPresetDirectory doesn't exist
        juce::File(mPresetDirectory).createDirectory();
    }
    storeLocalPreset();
    
}


KM_PresentManager::~KM_PresentManager()
{
}


void KM_PresentManager::getXmlForPreset(juce::XmlElement* inElement)
{
    //const int numParameters = mProcessor->getNumPrograms();
    
    //for (int i = 0; i<numParameters; i++){
    //    inElement->setAttribute(mProcessor->getParameterName(i),
    //                            mProcessor->getParameter(i));
    //}
    
    juce::XmlElement* presetName = new juce::XmlElement("preset_name");
    
    presetName->setAttribute("name", mCurrentPresetName);
    
    inElement->addChildElement(presetName);
    
    auto& parameters = mProcessor->getParameters();
    
    for(int i = 0; i < parameters.size(); i++){
        
        juce::AudioProcessorParameterWithID* parameter =
            (juce::AudioProcessorParameterWithID*)parameters.getUnchecked(i);
        
        inElement->setAttribute(parameter->paramID,
                                parameter->getValue());
    }
}



void KM_PresentManager::loadPresetForXml(juce::XmlElement* inElement)
{
//    mCurrentPresentXml = inElement;
//    const int numParameters = mProcessor->getNumPrograms();
//
//    for (int i = 0; i < numParameters; i++){
//
//        const juce::String name = mCurrentPresentXml->getAttributeName(i);
//        const float value = mCurrentPresentXml->getDoubleAttribute(name);
//
//
//        for (int j = 0; j < numParameters; j++){
//            if(mProcessor->getParameterName(j)==name){
//                mProcessor->setParameterNotifyingHost(j, value);
//            }
//        }
//    }
    
    mCurrentPresetXml = inElement;
    
    juce::XmlElement* presetName = inElement->getChildByName("preset_name");
    
    // early return if presetName element is nullptr
    if(presetName == nullptr){ return; }
    
    mCurrentPresetName = presetName->getStringAttribute("name", "error");
    
    /** iterate our XML for attribute name and value */
    auto& parameters = mProcessor->getParameters();
    
    for(int i = 0; i < mCurrentPresetXml->getNumAttributes(); i ++){
     
        const juce::String paramId = mCurrentPresetXml->getAttributeName(i);
        const float value = mCurrentPresetXml->getDoubleAttribute(paramId);
        
        for(int j = 0; j < parameters.size(); j++){
            
            juce::AudioProcessorParameterWithID* parameter =
            (juce::AudioProcessorParameterWithID*)parameters.getUnchecked(i);
            
            if(paramId == parameter->paramID){
                parameter->setValueNotifyingHost(value);
            }
        }
    }
    
    
    
}




int KM_PresentManager::getNumberOfPresets()
{
    return mLocalPresets.size();
}



juce::String KM_PresentManager::getPresetName(int inPresetIndex)
{
    return mLocalPresets[inPresetIndex].getFileNameWithoutExtension();
}



void KM_PresentManager::createNewPreset()
{
    const int numParameters = mProcessor->getNumParameters();
    
    for(int i=0; i<numParameters; i++){
        mProcessor->setParameterNotifyingHost(i, mProcessor->getParameterDefaultValue(i));
    }
    
    mCurrentPresetSaved = false;
    mCurrentPresetName = "Untitled";
}



void KM_PresentManager::savePreset()
{
    juce::MemoryBlock destinationData;
    
    mProcessor->getStateInformation(destinationData); //get info from mProcessor and store in destinationData
    
    mCurrentlyLoadedPreset.deleteFile();
    
    mCurrentlyLoadedPreset.appendData(destinationData.getData(),
                                      destinationData.getSize());
    mCurrentPresetSaved = true;
    
}


void KM_PresentManager::saveAsPreset(juce::String inPresetName)
{
    juce::File presetFile = juce::File(mPresetDirectory
                                       + DirectorySeperator
                                       + inPresetName
                                       + PRESET_FILE_EXTENSION);
    
    if(!presetFile.exists()){
        presetFile.create();
    }else{
        presetFile.deleteFile();
    }
    
    juce::MemoryBlock destinationData;
    
    mProcessor->getStateInformation(destinationData);
    
    presetFile.appendData(destinationData.getData(),
                          destinationData.getSize());
    
    mCurrentPresetSaved = true;
    mCurrentPresetName = inPresetName;
    
    storeLocalPreset();
}



void KM_PresentManager::loadPreset(int inPresetIndex)
{
    mCurrentlyLoadedPreset = mLocalPresets[inPresetIndex];
    juce::MemoryBlock PresentBinary;
    
    const int numParameters = mProcessor->getNumParameters();
    
    for(int i=0; i<numParameters; i++){
        mProcessor->setParameterNotifyingHost(i, mProcessor->getParameterDefaultValue(i));
    }
    
    if(mCurrentlyLoadedPreset.loadFileAsData(PresentBinary)){
        mCurrentPresetSaved = true;
        mCurrentPresetName = getPresetName(inPresetIndex);
        mProcessor->setStateInformation(PresentBinary.getData(),
                                        (int)PresentBinary.getSize());
    }
}



bool KM_PresentManager::getIsCurrentPresetSaved()
{
    return mCurrentPresetSaved;
}



juce::String KM_PresentManager::getCurrentPresetName()
{
    return mCurrentPresetName;
}



void KM_PresentManager::storeLocalPreset()
{
    mLocalPresets.clear();
    
    for(juce::DirectoryIterator di(juce::File(mPresetDirectory),
                             false,
                             "*"+(juce::String)PRESET_FILE_EXTENSION,
                             juce::File::TypesOfFileToFind::findFiles);
                             di.next();)
    {
        juce::File preset = di.getFile();
        mLocalPresets.add(preset);
    }
}
