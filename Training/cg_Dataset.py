import torch
from torch.utils.data import Dataset
from PIL import Image
import os
import numpy as np
import random
from torchvision import transforms

class load_data(Dataset):
    def __init__(self, folder, asImage = True, filecount = 0, transform = None):
        # Initialize variables globally
        self.folder = folder
        self.asImage = asImage
        self.orig_filecount = filecount
        self.filecount = filecount
        self.transform = transform
        
        if transform is not None:
            self.transform_img = transform[0]
            self.transform_mask = transform[1]
        
        # Get a list for "{folder}/image" and "{folder}/seg"
        self.image_list = os.listdir(f"./{folder}/image")
        self.seg_list = os.listdir(f"./{folder}/seg")
        
        # Check length of filecount
        if filecount == 0:
            self.filecount = len(self.image_list)
        
        # If asImage is true, load images into a list
        self.data, self.masks = self.load_images()

    def __getitem__(self, idx):
        printItems = False
        # If asImage is True, return the image and mask at that index
        # Otherwise load the image and mask at that index and return them
        if printItems: print("1. Loading Image")
        if self.asImage:
            image = self.data[idx]
            mask = self.masks[idx]
        else:
            image = Image.open(self.data[idx])
            mask = Image.open(self.masks[idx])
        
        if printItems: print("2. Converting to Numpy Array")
        # Convert each to a numpy array
        image = np.array(image)
        # Convert mask to tensor
        mask = np.array(mask)
        mask = torch.tensor(mask)
        mask = mask.unsqueeze(0)
        
        if printItems: print("3. Transposing Image")
        # If transform is not None, apply the transform to the image and mask
        if self.transform:
            image = self.transform_img(image)
            mask = self.transform_mask(mask)
        
        # Return the image and mask
        return image, mask

    def __len__(self):
        return self.filecount

    def load_images(self):
        temp_data = []
        temp_seg = []
        idx_s = []
        rand = -1
        
        # Load "filecount" # of images into a list
        for i in range(self.filecount):
            if self.orig_filecount == 0:
                # Load all images, in order of the list..
                if self.asImage:
                    temp_data.append(Image.open(f"./{self.folder}/image/{self.image_list[i]}"))
                    temp_seg.append(Image.open(f"./{self.folder}/seg/{self.seg_list[i]}"))
                else:
                    # Load the string location of the image
                    temp_data.append(f"./{self.folder}/image/{self.image_list[i]}")
                    temp_seg.append(f"./{self.folder}/seg/{self.seg_list[i]}")
            else:
                # Get a random image from the list, ranging from 0 to the length of the list
                while rand in idx_s or rand == -1: rand = random.randint(0, len(self.image_list) - 1)
                
                if self.asImage:
                    temp_data.append(Image.open(f"./{self.folder}/image/{self.image_list[rand]}"))
                    temp_seg.append(Image.open(f"./{self.folder}/seg/{self.seg_list[rand]}"))
                else:
                    # Load the string location of the image
                    temp_data.append(f"./{self.folder}/image/{self.image_list[rand]}")
                    temp_seg.append(f"./{self.folder}/seg/{self.seg_list[rand]}")
        
        return temp_data, temp_seg