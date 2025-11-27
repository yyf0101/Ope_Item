import json
import math

class MockEmbeddingModel:
    """
    A mock embedding model for demonstration.
    In a real system, this would use BERT/RoBERTa or OpenAI Embeddings.
    Here we use a simple keyword-based vectorizer to simulate semantic similarity.
    """
    def __init__(self):
        self.vocab = {
            "sync": 0, "timeout": 1, "nr": 2, "demodulation": 3, 
            "evm": 4, "handover": 5, "failure": 6, "wifi": 7, "preamble": 8
        }
        self.dim = len(self.vocab)

    def encode(self, text):
        text = text.lower()
        vector = [0.0] * self.dim
        tokens = text.split()
        for token in tokens:
            # Simple partial matching
            for key, idx in self.vocab.items():
                if key in token:
                    vector[idx] = 1.0
        
        # Normalize
        norm = math.sqrt(sum(x*x for x in vector))
        if norm > 0:
            vector = [x/norm for x in vector]
        return vector

class VectorDatabase:
    def __init__(self, db_file):
        with open(db_file, 'r') as f:
            self.documents = json.load(f)
        
        self.model = MockEmbeddingModel()
        self.vectors = []
        
        # Build Index
        print("Building Vector Index from Knowledge Base...")
        for doc in self.documents:
            # We embed the error signature and context combined
            text_to_embed = f"{doc['error_signature']} {doc['context']}"
            vec = self.model.encode(text_to_embed)
            self.vectors.append(vec)
            print(f"Indexed: {doc['id']}")

    def search(self, query_text, top_k=1):
        query_vec = self.model.encode(query_text)
        
        scores = []
        for i, doc_vec in enumerate(self.vectors):
            # Cosine Similarity
            dot_product = sum(q*d for q, d in zip(query_vec, doc_vec))
            scores.append((dot_product, self.documents[i]))
        
        # Sort by score descending
        scores.sort(key=lambda x: x[0], reverse=True)
        return scores[:top_k]
