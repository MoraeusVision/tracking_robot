FROM ultralytics/ultralytics:latest-jetson-jetpack6

WORKDIR /workspace

COPY . .

#RUN pip install -r requirements.txt

CMD ["/bin/bash"]
