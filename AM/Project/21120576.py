# import numpy as np
# import imageio
# import matplotlib.pyplot as plt

# def compress_image(image_path, k):
#     # Load the image
#     image = imageio.imread('hehe.png', as_gray=True)

#     # Convert the image to a 2D array
#     image_2d = np.reshape(image, (-1, image.shape[1]))

#     # Apply SVD on the image matrix
#     U, S, VT = np.linalg.svd(image)

#     # Retain the top 'k' singular values and corresponding vectors
#     U_k = U[:, :k]
#     S_k = np.diag(S[:k])
#     VT_k = VT[:k, :]

#     # Compress the image using the retained components
#     compressed_image_array = U_k @ S_k @ VT_k


#     # Reshape the reconstructed image
#     compressed_image = np.reshape(compressed_image_array, image.shape)

#     return compressed_image

# # Set the number of retained singular values (k) for compression
# k = 600

# # Provide the path to the input image
# image_path = "compressing_image.jpg"

# # Compress the image
# compressed_image = compress_image(image_path, k)

# fig, axes = plt.subplots(1, 2, figsize=(8, 4))

# image = imageio.imread('hehe.png', as_gray=True)

# axes[0].imshow(image, cmap='gray')
# axes[0].set_title('Original Image')
# axes[0].axis('off')
# axes[1].imshow(compressed_image, cmap='gray')
# axes[1].set_title('Reconstructed Image')
# axes[1].axis('off')
# plt.show()

import numpy as np
from sklearn.decomposition import PCA
import matplotlib.pyplot as plt
import imageio

# Load the image
image = imageio.imread('hehe.png', as_gray=True)

# Convert the image to a 2D array
image_2d = np.reshape(image, (-1, image.shape[1]))

# Perform PCA
pca = PCA(n_components=2)
image_pca = pca.fit_transform(image_2d)

# Reconstruct the image from PCA components
image_reconstructed = pca.inverse_transform(image_pca)

# Reshape the reconstructed image
image_reconstructed = np.reshape(image_reconstructed, image.shape)


# Plot the original image and the reconstructed image
fig, axes = plt.subplots(1, 2, figsize=(8, 4))
axes[0].imshow(image, cmap='gray')
axes[0].set_title('Original Image')
axes[0].axis('off')
axes[1].imshow(image_reconstructed, cmap='gray')
axes[1].set_title('Reconstructed Image')
axes[1].axis('off')
plt.show()
